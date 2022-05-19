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

// Agent timeBasedActuatorAgent in project greenhouse_core

/* Initial goals */

!checkSettings.

/* Plans */

/*
 * Components: the list of components found in the greenhouse.
 * Plan that is triggered when new components are found and the observable property
 * is updated.
 */
+setupComponents(Components) <- setupComponents(Components).

/*
 * Settings: the list of settings found that are set by the user.
 * Plan that is triggered when new settings are found and the observable property
 * is updated.
 */
+setupSettings(Settings) <- setupSettings(Settings).

/*
 * Tds: the list of thing descriptors that contains all the properties and the 
 * actions of all the components in the greenhouse.
 * Plan that is triggered when new settings are found and the observable property
 * is updated.
 */
+setupTds(Tds) <- setupTds(Tds).

/*
 * This is the initial goal that starts at the beginning of the agent initialization.
 * It is used to retrieve the category that it handles from the BB and to check
 * the Hour setting of that category and perform and action in based on the settings.
 * This goal triggers the wait plan, which starts a loop.
 */
+!checkSettings <- ?category(Category); checkSettings(Category); !wait.

/*
 * This plan is part of the loop for the checks of the settings.
 * It wait for X seconds and then it checks the settings again in order
 * to check if after X seconds an action has to be performed.
 */
+!wait <- .at("now + 10 seconds", {+!checkSettings}).

{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }
