// Agent samplingAgent in project greenhouse_core

/* Initial beliefs and rules */

/* Initial goals */

/* Plans */

+setup(D, T) <- setup(D,T); +wait.

+wait <- .at("now + 2 seconds", {+sample}).

+sample <- ?role(R); sampleOperation(R); -+wait.

{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }

// uncomment the include below to have an agent compliant with its organisation
//{ include("$moiseJar/asl/org-obedient.asl") }
