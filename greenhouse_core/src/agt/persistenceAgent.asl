// Agent persistenceAgent in project greenhouse_core

/* Initial beliefs and rules */

/* Initial goals */

/* Plans */

+uploadPersistence(Sample) <- ?token(Token); uploadPersistence(Sample, Token).

{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }

// uncomment the include below to have an agent compliant with its organisation
//{ include("$moiseJar/asl/org-obedient.asl") }
