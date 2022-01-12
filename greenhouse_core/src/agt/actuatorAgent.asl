// Agent actuatorAgent in project greenhouse_core

/* Initial beliefs and rules */

/* Initial goals */

/* Plans */

+setup(Devices, Settings) <- setup(Devices, Settings); !wait.

+!wait <- .at("now + 10 seconds", {+!checkSettings}).

+!checkSettings <- ?category(Category); checkSettings(Category); !wait.

/*
 * Sample: Sample that caused an out of range status.
 * Setting: Setting that are violated by the sample current value.
 * Plan that is triggered when a Sample does not respect the current settings.
 */
+actuate(Sample, Setting) <- actuate(Sample, Setting).

{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }
