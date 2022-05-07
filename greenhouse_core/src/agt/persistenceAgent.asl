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
