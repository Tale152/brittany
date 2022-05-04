// Agent discoverComponentsAgent in project greenhouse_core

/* Initial goals */

!discover.

/* Plans */

/*
 * Initial goal used to start discover if there are new edges with different
 * components connected than the ones already discovered.
 * This also start a loop of requests to discover new components
 * in regular time intervals.
 */
+!discover <- discoverComponents; !wait.

/*
 * Plan used to start a loop that is going to trigger again the initial goal
 * every X seconds, in order to update the components if necessary.
 */
+!wait <- .at("now + 20 seconds", {+!discover}).

{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }
