Pod::Spec.new do |s|
    s.name                      = "AirBridge"
    s.version                   = "1.33.2"
    s.homepage                  = "https://airbridge.io"
    s.license                   = "Commercial"
    s.author                    = { "ab180" => "subeom@ab180.co" }
    s.platform                  = :ios, 11.0

    s.source                    = { 
        :http => "https://sdk-download.airbridge.io/frameworks/AirBridge.xcframework-1.33.2.zip"
    }
    s.preserve_paths            = "AirBridge_Files/AirBridge.xcframework"

    s.vendored_frameworks       = "AirBridge_Files/AirBridge.xcframework"
    s.ios.weak_frameworks       = "AdSupport", "iAd", "AdServices", "CoreTelephony", "StoreKit", "AppTrackingTransparency", "WebKit"

    s.summary                   = "Airbridge SDK for iOS"
    s.description               = <<-DESC
        A Neat and handy tool.
        Optimized for all purposes.
        Efficient marketing through paid-ad channel support and full stats report

        Easy attribution
        One SDK, instant tracking for all ads
        Deep-link support and app user tracking
        ab180 supports all standards Deep-links (Facebook Applinks, Android Applinks and iOS Universal Link...), designed for app user tracking from web to install and conversions
        Social Campaign Performance Tracking
        Tracking Link tracks all paid-ad channels and attributes credits to campaigns
        Paid-ad channel integration
        airbridge tracking links provide you instant campaign tracking for all paid-ad channels
        Mobile specific performance index
        Tracking by unique users
        Customizable In-App Events Tracking
        Add a goal and track user conversions
        No double charge
        One conversion counts one attribution. Free of double counts // Customizable lookback window

        kr: https://airbridge.io
        en: https://airbridge.io/en
    DESC

end
