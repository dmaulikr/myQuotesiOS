// Generated by Apple Swift version 2.2 (swiftlang-703.0.18.8 clang-703.0.31)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if defined(__has_include) && __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
# if defined(__has_feature) && __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if defined(__has_feature) && __has_feature(modules)
@import ObjectiveC;
@import Foundation;
@import Dispatch;
@import Foundation.NSURLSession;
@import UIKit;
@import CoreGraphics;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class NSMutableURLRequest;
@class NSURLSessionConfiguration;
@protocol ImageDownloaderDelegate;


/// ImageDownloader represents a downloading manager for requesting the image with a URL from server.
SWIFT_CLASS("_TtC10Kingfisher15ImageDownloader")
@interface ImageDownloader : NSObject

/// This closure will be applied to the image download request before it being sent. You can modify the request for some customizing purpose, like adding auth token to the header or do a url mapping.
@property (nonatomic, copy) void (^ _Nullable requestModifier)(NSMutableURLRequest * _Nonnull);

/// The duration before the download is timeout. Default is 15 seconds.
@property (nonatomic) NSTimeInterval downloadTimeout;

/// A set of trusted hosts when receiving server trust challenges. A challenge with host name contained in this set will be ignored. You can use this set to specify the self-signed site. It only will be used if you don't specify the authenticationChallengeResponder. If authenticationChallengeResponder is set, this property will be ignored and the implemention of authenticationChallengeResponder will be used instead.
@property (nonatomic, copy) NSSet<NSString *> * _Nullable trustedHosts;

/// Use this to set supply a configuration for the downloader. By default, NSURLSessionConfiguration.ephemeralSessionConfiguration() will be used. You could change the configuration before a downloaing task starts. A configuration without persistent storage for caches is requsted for downloader working correctly.
@property (nonatomic, strong) NSURLSessionConfiguration * _Nonnull sessionConfiguration;

/// Whether the download requests should use pipeling or not. Default is false.
@property (nonatomic) BOOL requestsUsePipeling;

/// Delegate of this ImageDownloader object. See ImageDownloaderDelegate protocol for more.
@property (nonatomic, weak) id <ImageDownloaderDelegate> _Nullable delegate;
@property (nonatomic, readonly, strong) dispatch_queue_t _Nonnull barrierQueue;
@property (nonatomic, readonly, strong) dispatch_queue_t _Nonnull processQueue;

/// The default downloader.
+ (ImageDownloader * _Nonnull)defaultDownloader;

/// Init a downloader with name.
///
/// \param name The name for the downloader. It should not be empty.
///
/// \returns  The downloader object.
- (nonnull instancetype)initWithName:(NSString * _Nonnull)name OBJC_DESIGNATED_INITIALIZER;
@end

@class NSURL;

@interface ImageDownloader (SWIFT_EXTENSION(Kingfisher))
- (void)cleanForURL:(NSURL * _Nonnull)URL;
@end

@class UIImage;
@class NSURLResponse;


/// Protocol of ImageDownloader.
SWIFT_PROTOCOL("_TtP10Kingfisher23ImageDownloaderDelegate_")
@protocol ImageDownloaderDelegate
@optional

/// Called when the ImageDownloader object successfully downloaded an image from specified URL.
///
/// \param downloader The <code>ImageDownloader
/// </code> object finishes the downloading.
///
/// \param image Downloaded image.
///
/// \param URL URL of the original request URL.
///
/// \param response The response object of the downloading process.
- (void)imageDownloader:(ImageDownloader * _Nonnull)downloader didDownloadImage:(UIImage * _Nonnull)image forURL:(NSURL * _Nonnull)URL withResponse:(NSURLResponse * _Nonnull)response;
@end

@class NSURLSession;
@class NSURLSessionDataTask;
@class NSData;
@class NSURLSessionTask;
@class NSError;
@class NSURLAuthenticationChallenge;
@class NSURLCredential;


/// Delegate class for NSURLSessionTaskDelegate. The session object will hold its delegate until it gets invalidated. If we use ImageDownloader as the session delegate, it will not be released. So we need an additional handler to break the retain cycle.
SWIFT_CLASS("_TtC10Kingfisher29ImageDownloaderSessionHandler")
@interface ImageDownloaderSessionHandler : NSObject <NSURLSessionDataDelegate, NSURLSessionDelegate, NSURLSessionTaskDelegate>
@property (nonatomic, strong) ImageDownloader * _Nullable downloadHolder;

/// This method is exposed since the compiler requests. Do not call it.
- (void)URLSession:(NSURLSession * _Nonnull)session dataTask:(NSURLSessionDataTask * _Nonnull)dataTask didReceiveResponse:(NSURLResponse * _Nonnull)response completionHandler:(void (^ _Nonnull)(NSURLSessionResponseDisposition))completionHandler;

/// This method is exposed since the compiler requests. Do not call it.
- (void)URLSession:(NSURLSession * _Nonnull)session dataTask:(NSURLSessionDataTask * _Nonnull)dataTask didReceiveData:(NSData * _Nonnull)data;

/// This method is exposed since the compiler requests. Do not call it.
- (void)URLSession:(NSURLSession * _Nonnull)session task:(NSURLSessionTask * _Nonnull)task didCompleteWithError:(NSError * _Nullable)error;

/// This method is exposed since the compiler requests. Do not call it.
- (void)URLSession:(NSURLSession * _Nonnull)session didReceiveChallenge:(NSURLAuthenticationChallenge * _Nonnull)challenge completionHandler:(void (^ _Nonnull)(NSURLSessionAuthChallengeDisposition, NSURLCredential * _Nullable))completionHandler;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


@interface NSData (SWIFT_EXTENSION(Kingfisher))
@end


@interface NSMutableData (SWIFT_EXTENSION(Kingfisher))
@end


@interface UIImage (SWIFT_EXTENSION(Kingfisher))
+ (UIImage * _Nullable)kf_imageWithData:(NSData * _Nonnull)data scale:(CGFloat)scale preloadAllGIFData:(BOOL)preloadAllGIFData;
@end


@interface UIImage (SWIFT_EXTENSION(Kingfisher))
- (UIImage * _Nullable)kf_decodedImage;
- (UIImage * _Nullable)kf_decodedImageWithScale:(CGFloat)scale;
@end


@interface UIImage (SWIFT_EXTENSION(Kingfisher))
+ (UIImage * _Nullable)kf_animatedImageWithGIFDataWithGifData:(NSData * _Nonnull)data preloadAll:(BOOL)preloadAll;
+ (UIImage * _Nullable)kf_animatedImageWithGIFDataWithGifData:(NSData * _Nonnull)data scale:(CGFloat)scale duration:(NSTimeInterval)duration preloadAll:(BOOL)preloadAll;
@end


@interface UIImage (SWIFT_EXTENSION(Kingfisher))
+ (UIImage * _Nonnull)kf_imageWithCGImage:(CGImageRef _Nonnull)cgImage scale:(CGFloat)scale refImage:(UIImage * _Nullable)refImage;

/// Normalize the image. This method will try to redraw an image with orientation and scale considered.
///
/// \returns  The normalized image with orientation set to up and correct scale.
- (UIImage * _Nonnull)kf_normalizedImage;
+ (UIImage * _Nullable)kf_animatedImageWithImages:(NSArray<UIImage *> * _Nonnull)images duration:(NSTimeInterval)duration;
@end


@interface UIImage (SWIFT_EXTENSION(Kingfisher))
@property (nonatomic, readonly) NSInteger kf_imageCost;
@end


@interface UIImage (SWIFT_EXTENSION(Kingfisher))
@property (nonatomic, readonly) CGFloat kf_scale;
@property (nonatomic, readonly, copy) NSArray<UIImage *> * _Nullable kf_images;
@property (nonatomic, readonly) NSTimeInterval kf_duration;
@property (nonatomic, readonly, strong) NSData * _Nullable kf_animatedImageData;
@end

#pragma clang diagnostic pop
