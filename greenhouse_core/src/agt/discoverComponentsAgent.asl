// Agent discoverComponentsAgent in project greenhouse_core

/* Initial beliefs and rules */

/* Initial goals */

!discover.

/* Plans */

+!discover <- discoverComponents; !wait.

+!wait <- .at("now + 20 seconds", {+!discover}).

{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }
