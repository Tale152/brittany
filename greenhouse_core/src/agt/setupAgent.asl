/*
 * Copyright (C) 2022 Angelo Filaseta, Alessandro Talmi, Elisa Tronetti
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// Agent setupAgent in project greenhouse_core

/* Initial goals */

/*
 * Initial goal, that is going to start the authentication process to the services.
 */
!authentication.

/* Plans */

/*
 * When this plan is triggered, it is going to use the operation to actually authenticate to the remote services.
 */
+!authentication <- retrieveAuthenticationData.

/*
 * Token: Token obtained by the authentication proccess.
 * This plan is triggered when the authentication has been successfully made. With the token,
 * it is going to ask for settings and start a loop adding the plan wait.
 */
+token(Token) <- getSettings(Token); !wait.

/*
 * Settings: the settings retrieved by the settings service.
 * This plan is triggered when the settings property is added to the BB,
 * in order to updated the settings with all the other agents that use them.
 */
+settings(Settings) <- shareSettings(Settings).

/*
 * This plan is used to perform the request of the settings periodically, every X seconds.
 */
+!wait <- .at("now + 20 seconds", {+!updateSettings}).

/*
 * Token: Token is the authentication token used to receive a responce from the settings service.
 * This plan is used to find the authentication Token from the BB and ask the settings service
 * for the updated version of the settings.
 * After that, it is called the wait plan in order to create a loop.
 */
+!updateSettings <- ?token(Token); getSettings(Token); !wait.

{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }
