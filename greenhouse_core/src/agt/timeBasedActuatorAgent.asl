// Agent actuatorAgent in project greenhouse_core

/* Initial beliefs and rules */

/* Initial goals */

!checkSettings.

/* Plans */

+setupComponents(Components) <- setupComponents(Components).

+setupSettings(Settings) <- setupSettings(Settings).

+setupTds(Tds) <- setupTds(Tds).

+!checkSettings <- ?category(Category); checkSettings(Category); !wait.

+!checkSettings <- !wait.

+!wait <- .at("now + 10 seconds", {+!checkSettings}).

{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }
