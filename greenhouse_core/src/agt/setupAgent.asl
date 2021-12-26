// Agent setupAgent in project greenhouse_core

/* Initial beliefs and rules */

/* Initial goals */

!authentication.

/* Plans */

+!authentication <- retrieveAuthenticationData.

+token(T) <- getSettings(T, S); initAfterAuthentication(T, S).

//initAfterAuthentication

{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }

// uncomment the include below to have an agent compliant with its organisation
//{ include("$moiseJar/asl/org-obedient.asl") }
