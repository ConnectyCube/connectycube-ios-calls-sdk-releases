# ConnectyCube iOS Calls SDK Releases

This repository contains releases of the iOS Calls SDK. It provides a simple interface to the video calling capabilities provided by the ConnectyCube platform.

If you have any questions, comments, or issues related to any products distributed via this repository then please raise an issue here on GitHub repository or contact the team by emailing support@connectycube.com.

# ConnectyCube SDK

This repository contains releases of the iOS SDK for interacting with the ConnectyCube communications cloud.

It provides a simple interface to the video calling (WebRTC) capabilities provided by the platform. 

[Getting Started with ConnectyCube iOS SDK](https://developers.connectycube.com/ios/)

# Installation

The ConnectyCube iOS Calls SDK can be installed directly into your application by adding sdk libraries via CocoaPods.

Make sure that you have [CocoaPods](http://cocoapods.org/) installed.

Open your Podfile and add following line for dynamic framework (iOS 9+):

```
pod 'ConnectyCubeCalls'
```

Then add a "Run Script Phase" in build phases of your project. Past the following snippet in the script:

```
bash "${BUILT_PRODUCTS_DIR}/${FRAMEWORKS_FOLDER_PATH}/ConnectyCubeCalls.framework/strip-framework.sh"
```

This fixes a [known Apple bug](http://www.openradar.me/radar?id=6409498411401216), that does not allowing to publish archives to the App store with dynamic frameworks that contains simulator platforms. Script will only work for archiving.

Then open **Terminal** go to your project folder with Podfile and run:

```
pod install
```

Now you can open **.xcworkspace** file and use ConnectyCube Framework in your project. 

# Contact

You can reach the ConnectyCube team at any time by emailing [support@connectycube.com](mailto:support@connectycube.com).

# Licence 

ConnectyCube Calls SDK for iOS is licensed under the ConnectyCube SDK License.
