Copyright 2015, ATEGRA

Protogrid for iOS
=================

Requirements
------------
1. You will need a Mac with Xcode 6.1 or later.
2. This version of the Protogrid iOS client is compatible with iOS 8.1 and later running on iPhone and iPad (any screen size).
3. It is recommended to use the Protogrid iOS client with iPhone 5 / iPad 4 / iPad mini 2 (or later).

Basic Setup
-----------
1. Download the latest Protogrid iOS client zipfile by going to your app in the web interface, opening `Import|Export` and clicking the `Rollout to iOS` button.
2. Open the Protogrid.xcodeproj file in your Xcode.
3. Set the following properties in `General/PGridInfo.plist`:
  a. Application Database ID. You find this by opening any Card in your application and clicking `This Card -> Show Properties`.
  b. Protogrid Host. This is your environment root URL without `http://`, e.g. `my-environment.protogrid.com`.
  c. (optional) Application Version.
  d. (optional) Bundle display name.
4. Choose a Simulator as your build target and build & run the project (the 'play' button).
5. The initial replication of your application will begin. Please read the instructions on the screen carefully and follow them until you get to a success message. This should take 1-2 minutes, depending on your internet connection, and will download all design data associated with your application into an initial database state.
6. Your app should now build & run both on device and simulator. From here you can use any of Apple's provided rollout options (Enterprise rollout, Testflight internal testing, Testflight Beta testing, AppStore).

Versioning
----------
The code used in this project is bound to a specific Protogrid environment version and does not automatically update itself. When Protogrid updates, the new zipfile should be downloaded and rolled out to your user's devices. Therefore, if you have Protogrid iOS apps rolled out to production, your environment should not be updated automatically. As soon as a new Protogrid version rolls out after the release, you will have the option to control when/if your environment will be updated, so that you can coordinate the update with a new iOS rollout. Protogrid will always be updated during maintenance windows that fall into the weekend for all timezones.

Independently you also have the version number for your own app, which is set in two places: `General/PGridInfo.plist` and in the build settings. This version will show up in the replicator page (cogwheel) and in the AppStore if you choose to roll out your app there.

Rolling Out a New Version
-------------------------
If you have updated ScriptLibraries or you would like new users to get an updated state packaged in the app bundle, you can simply change the version number in `General/PgridInfo.plist` and build & run the project for the simulator - this will reseed your databases (like Basic Setup step 4).

Replication of Cards
--------------------
Replication settings are defined by the application developer as follows:
1. Design Cards (Proto definitions, field definitions, application properties, ...) will always be replicated.
2. Script Libraries, Database Design Documents and Logfiles will never be replicated.
3. Data Cards will be replicated when your users open up the app for the first time and continuously afterwards. Please note that it will require a refresh of the Overview Card to see newly replicated data. To do this, you can tap the menu entry for that Overview Card.