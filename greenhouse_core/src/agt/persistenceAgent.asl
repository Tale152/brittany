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

// Agent persistenceAgent in project greenhouse_core

/* Plans */

/*
 * Sample: Sample is the avarage Sample that has been calculated as the avarage
 * of all the samples of the same category of components.
 * Token: Token is the authentication token that is in the BB of this agent.
 * This plan is triggered when it is requested to upload a certain sample in the
 * persistence service (performed by the PersistenceArtifact).
 */
+uploadPersistence(Sample) <- ?token(Token); uploadPersistence(Sample, Token).

{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }
