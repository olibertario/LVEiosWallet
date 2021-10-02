//
//  GNBridgeModule.h
//  GoNativeCore
//
//  Created by Hunaid Hassan on 21.06.21.
//

#import <Foundation/Foundation.h>
#import "GNDefines.h"
#import "GNJavascriptRunner.h"

@class GNBridge;
@protocol GNBridgeMethod;

@protocol GNBridgeModule <NSObject>

#define GN_EXPORT_MODULE() \
GN_EXTERN void GNRegisterModule(Class); \
+ (void)load { GNRegisterModule(self); }

@optional
- (BOOL)runner:(id<GNJavascriptRunner>)runner shouldLoadRequestWithURL:(NSURL*)url;
- (void)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;
- (void)applicationWillResignActive:(UIApplication *)application;
- (void)applicationDidEnterBackground:(UIApplication *)application;
- (void)applicationWillEnterForeground:(UIApplication *)application;
- (void)applicationWillTerminate:(UIApplication *)application;
- (void)applicationDidBecomeActive:(UIApplication *)application;
@end
