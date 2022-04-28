// Agent samplingAgent in project greenhouse_core

/* Initial beliefs and rules */

/* Initial goals */

/* Plans */

/*
 * Devices: Devices is the full list of Device that the enviroment will have to communicate with.
 * Settings: Settings are all the settings retrieved from the settings service.
 * This plan is triggered when the setup property is added to the BB. This property has all
 * the devices and the settings in order to start the sampling process.
 */

+setupComponents(Components) <- setupComponents(Components); !wait.

+setupSettings(Settings) <- setupSettings(Settings).

/*
 * This plan waits X seconds to trigger the plan sample, which is used to ask for the sample of a specific category.
 */
+!wait <- .at("now + 5 seconds", {+!sample}).

/*
 * Category: Category is the specific type of devices requested to sample. 
 * This plan, once triggered, is going to take from the BB the Category assigned to the agent and it will sample
 * the devices of that category. After that, we trigger again the wait plan, creating a loop.
 */
+!sample <- ?category(Category); sampleOperation(Category); !wait.

{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }
