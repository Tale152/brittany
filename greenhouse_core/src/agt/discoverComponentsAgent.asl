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
 
// Agent discoverComponentsAgent in project greenhouse_core

/* Initial goals */

!discover.

/* Plans */

/*
 * Initial goal used to start discover if there are new edges with different
 * components connected than the ones already discovered.
 * This also start a loop of requests to discover new components
 * in regular time intervals.
 */
+!discover <- discoverComponents.

/*
 * Plan used to start a loop that is going to trigger again the initial goal
 * every X seconds, in order to update the components if necessary.
 */
+wait <- .at("now + 20 seconds", {+!discover}).

/*
 * Plan that is triggered when the list of components is updated.
 * This plan uses the common artifact to share the components to 
 * all the other agents that need them.
 */
+components(Components) <- shareComponents(Components).

/*
 * Plan that is triggered when the list of thing descriptors is updated.
 * This plan uses the common artifact to share the components to
 * all the other agents that need them.
 */
+thingDescriptors(Td) <- shareThingDescriptors(Td).

{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }
