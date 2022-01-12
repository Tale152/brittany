// Agent setupAgent in project greenhouse_core

/* Initial beliefs and rules */

/* Initial goals */

/*
 * Initial goal, that is going to start the authentication process to the services.
 */
!authentication.

/* Plans */

/*
 * When this plan is triggered, it is going to use the operation to actually authenticate to the remote services.
 */
+!authentication <- retrieveAuthenticationData.

/*
 * Token: Token obtained by the authentication proccess.
 * This plan is triggered when the authentication has been successfully made. With the token, it is going to ask for settings
 * and start a loop adding the plan wait.
 */
+token(Token) <- getSettings(Token); !wait.

/*
 * Settings: the settings retrieved by the settings service.
 * This plan is triggered when the settings property is added to the BB, in order to updated the settings with all the
 * other agents that use them.
 */
+settings(Settings) <- shareSettings(Settings).

/*
 * This plan is used to perform the request of the settings periodically, every X seconds.
 */
+!wait <- .at("now + 20 seconds", {+!updateSettings}).

/*
 * Token: Token is the authentication token used to receive a responce from the settings service.
 * This plan is used to find the authentication Token from the BB and ask the settings service for the updated version of the
 * settings. After that, it is called the wait plan in order to create a loop.
 */
+!updateSettings <- ?token(Token); getSettings(Token); !wait.

+components(Components) <- shareComponents(Components).

+thingDescriptors(Td) <- shareThingDescriptors(Td).

{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }
