//
//  GNBridge.h
//  GoNativeCore
//
//  Created by Hunaid Hassan on 21.06.21.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import "GNJavascriptRunner.h"

NS_ASSUME_NONNULL_BEGIN

@interface GNBridge : NSObject

@property (nonatomic, copy, readonly) NSDictionary *launchOptions;

- (BOOL)runner:(id<GNJavascriptRunner>)runner shouldLoadRequestWithURL:(NSURL*)url;
- (void)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;
- (void)applicationWillResignActive:(UIApplication *)application;
- (void)applicationDidEnterBackground:(UIApplication *)application;
- (void)applicationWillEnterForeground:(UIApplication *)application;
- (void)applicationWillTerminate:(UIApplication *)application;
- (void)applicationDidBecomeActive:(UIApplication *)application;
- (void)loadUserScriptsForContentController:(WKUserContentController *)userController;

@end

NS_ASSUME_NONNULL_END
