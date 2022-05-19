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

// Agent samplingAgent in project greenhouse_core

/* Plans */

/*
 * Tds: the list of thing descriptor that contains all the properties and the 
 * actions of all the components in the greenhouse.
 * Plan that is triggered when new tds are found and the observable property
 * is updated.
 */
+setupTds(Tds) <- setupTds(Tds).

/*
 * Components: Components that are involved to retrieve samples, which are part of a specific
 * category.
 * Plan that is triggered when a list of Components has to be sampled.
 */
+sampling(Components) <- getSamples(Components).

{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }
