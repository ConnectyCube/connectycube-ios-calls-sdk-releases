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

## Have an issue?

Join our [Discord](https://discord.com/invite/zqbBWNCCFJ) for quick answers to your questions

## Community

- [Blog](https://connectycube.com/blog)
- X (twitter)[@ConnectyCube](https://x.com/ConnectyCube)
- [Facebook](https://www.facebook.com/ConnectyCube)

**Want to support our team**:<br>
<a href="https://www.buymeacoffee.com/connectycube" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-blue.png" alt="Buy Me A Coffee" style="height: 60px !important;width: 217px !important;" ></a>

# License 

ConnectyCube Calls SDK for iOS is licensed under the ConnectyCube SDK License.
