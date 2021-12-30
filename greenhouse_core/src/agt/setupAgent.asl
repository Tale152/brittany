// Agent setupAgent in project greenhouse_core

/* Initial beliefs and rules */

/* Initial goals */

!authentication.

/* Plans */

+!authentication <- retrieveAuthenticationData.

+token(Token) <- getSettings(Token, Settings); initAfterAuthentication(Settings); !wait.

+!wait <- .at("now + 5 seconds", {+!settings}).

+!settings <- ?token(Token); getSettings(Token, Settings); !wait.

{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }

// uncomment the include below to have an agent compliant with its organisation
//{ include("$moiseJar/asl/org-obedient.asl") }
