//
//  GNEventEmitter.m
//  GoNativeCore
//
//  Created by Hunaid Hassan on 07.07.21.
//

#import "GNEventEmitter.h"

@implementation GNEventEmitter

- (NSString *)createJSForCallback:(NSString *)name, ... NS_REQUIRES_NIL_TERMINATION {
    NSMutableArray *params = [[NSMutableArray alloc] initWithObjects:name, nil];
    va_list args;
    va_start(args, name);
    
    id arg = nil;
    while ((arg = va_arg(args, id)) != nil) {
        [params addObject:arg];
    }

    va_end(args);
    
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:params options:0 error:nil];
    if (!jsonData) {
        return nil;
    }
    NSString * jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
    
    return [NSString stringWithFormat:@"function gonative_do_callback() {"
     "var args = Array.from(arguments);"
     "var fnName = args.shift();"
     "if (typeof window[fnName] !== 'function') { return };"
        "try{"
            "var callBackFn = window[fnName];"
            "callBackFn(...args);"
        "}catch(ignored){}"
     "}"
     "gonative_do_callback(...%@)", jsonString];
}

@end
