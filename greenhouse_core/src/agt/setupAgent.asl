// Agent setupAgent in project greenhouse_core

/* Initial beliefs and rules */

/* Initial goals */

!authentication.

/* Plans */

+!authentication <- retrieveAuthenticationData.

+token(Token) <- getSettings(Token); !wait.

+settings(Settings) <- shareSettings(Settings).

+!wait <- .at("now + 2 seconds", {+!updateSettings}).

+!updateSettings <- ?token(Token); getSettings(Token); !wait.


{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }

// uncomment the include below to have an agent compliant with its organisation
//{ include("$moiseJar/asl/org-obedient.asl") }
