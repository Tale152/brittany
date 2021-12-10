// Agent samplingAgent in project greenhouse_core

/* Initial beliefs and rules */

/* Initial goals */

/* Plans */

+devices(D) <- initDevices(D); +wait.

+wait <- .at("now + 2 seconds", {+sample}).

+sample <- sampleOperation; -+wait.

{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }

// uncomment the include below to have an agent compliant with its organisation
//{ include("$moiseJar/asl/org-obedient.asl") }
