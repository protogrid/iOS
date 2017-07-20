Copyright 2017, ATEGRA AG

Protogrid for iOS
=================

Requirements
------------
1. You will need a Mac with current a Xcode version.
2. This version of the Protogrid iOS client is compatible with iOS 8.1 and later running on iPhone and iPad (any screen size).
3. It is recommended to use the Protogrid iOS client with iPhone 5 / iPad 4 / iPad mini 2 (or later).

Basic Setup
-----------
1. Download the latest Protogrid iOS client zipfile by going to your app in the web interface, opening `Import|Export` and clicking the `Rollout to iOS` button.
2. Open the Protogrid.xcodeproj file in your Xcode.
3. Set the following properties in `General/PGridInfo.plist`:
  a. Application Database ID. You find this by opening any Card in your application and clicking `This Card -> Show Properties`.
  b. Protogrid Host. This is your environment root URL without `http://`, e.g. `my-environment.protogrid.com`.
  c. Bundle Identifier. This is used by Apple to identify your app and should be of the form "com.your-organization.your-department.your-appname". It is important to choose a different Bundle Identifier for each of your apps.
  d. Bundle display name.
4. Choose a Simulator as your build target and build & run the project (the 'play' button).
5. The initial replication of your application will begin. Please read the instructions on the screen carefully and follow them until you get to a success message. This should take 1-2 minutes, depending on your internet connection, and will download all design data associated with your application into an initial database state.
6. Your app should now build & run both on device and simulator. From here you can use any of Apple's provided rollout options (Enterprise rollout, Testflight internal testing, Testflight Beta testing, AppStore). Make sure to select the Release build scheme for the archive build you'd like to submit.

Client Version
--------------
The code used in this project is bound to a specific Protogrid environment version and does not automatically update itself. When Protogrid updates, the new zipfile should be downloaded and rolled out to your user's devices. Therefore, if you have Protogrid iOS apps rolled out to production, your environment should not be updated automatically. As soon as a new Protogrid version rolls out after the release, you will have the option to control when/if your environment will be updated, so that you can coordinate the update with a new iOS rollout. Protogrid will always be updated during maintenance windows that fall into the weekend for all timezones.

Independently you also have the version number for your own app, which is set in the build settings (see below). This version will show up in the replicator page (cogwheel) as well as the associated version of your Protogrid environment.

Rolling Out a New App Version
-----------------------------
If you have updated ScriptLibraries or you would like new users to get an updated state packaged in the app bundle, you can change the version number as follows:
1. Click on the project in the side bar.
2. Select your target.
3. Go to `Build Settings`.
4. Increment the entry under `Current Project Version`.
5. Clean your project.
6. Build & run the project for the simulator - this will re-seed your databases (like Basic Setup step 4).

Replication of Cards
--------------------
Replication settings are defined by the application developer as follows:
1. Design Cards (Proto definitions, field definitions, application properties, ...) will always be replicated.
2. Script Libraries, Database Design Documents and Logfiles will never be replicated.
3. Data Cards will be replicated according to the settings made in Configuration/PGridReplication.plist. The Key of this Property List must contain a "proto_key" whereas the value specifies how all Cards with this "proto_key" will be replicated. There are 3 possible values:
    - "high": Cards will be replicated first when user opens app.
    - "medium" (default): New Cards will be replicated when user opens app after all high priority Cards. Cards, older than specified by "Threshold Document Age in Days" (default 1 week) or with attachments bigger than specified by "Threshold Document Attachment Size in Byte" (default 1MiB), will be replicated after all high priority and new/big medium priority Cards have been replicated.
    - "never": Cards will never be replicated.
4. Data Cards will be replicated when your users open up the app for the first time and continuously afterwards. Please note that it will require a refresh of the Overview Card to see newly replicated data. To do this, you can tap the menu entry for that Overview Card.