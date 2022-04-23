// Agent actuatorAgent in project greenhouse_core

/* Initial beliefs and rules */

/* Initial goals */

!checkSettings.

/* Plans */

+setup(Components, Settings) <- setupComponents(Components, Settings).

+setupTd(Td) <- setupTd(Td).

+!checkSettings <- ?category(Category); checkSettings(Category); !wait.

+!checkSettings <- !wait.

+!wait <- .at("now + 10 seconds", {+!checkSettings}).

{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }
