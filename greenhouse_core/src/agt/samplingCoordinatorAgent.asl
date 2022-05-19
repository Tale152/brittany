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

// Agent samplingCoordinatorAgent in project greenhouse_core

/* Initial goals */

!sample.

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
 * Category: Category is the specific type of devices requested to sample.
 * This is the initial goal, which is going to perform a sample operation on a components
 * that have a specific Category, which is the one that is in the BB of the agent.
 * Then it will trigger the wait plan, creating a loop of sampling that is performed
 * in regular time intervals.
 */
+!sample <- ?category(Category); sampleOperation(Category); !wait.

/*
 * This plan waits X seconds to trigger the plan sample, 
 * which is used to ask for the sample of a specific category.
 */
+!wait <- .at("now + 5 seconds", {+!sample}).

/*
 * Category: the category of the Samples retrieved.
 * Samples: the list of samples just retrieved from the Components.
 * This plan is used to check the samples just retrieved from the sampling agent.
 * The category of the samples must match the category in the BB of the agent, 
 * and the samples are going to be updated on the persistence service if necessary,
 * and an actuator will be actionated if the samples create an out of range behaviour.
 */
+checkSamples(Category, Samples) : category(Category) <- updateOperation(Samples).

{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }
