// Agent samplingAgent in project greenhouse_core

/* Initial beliefs and rules */

/* Initial goals */

/* Plans */

+setup(Devices, Settings) <- setup(Devices, Settings); !wait.

+!wait <- .at("now + 5 seconds", {+!sample}).

+!sample <- ?role(Role); sampleOperation(Role); !wait.

{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }

// uncomment the include below to have an agent compliant with its organisation
//{ include("$moiseJar/asl/org-obedient.asl") }
