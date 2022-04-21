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

/*
 * Category: the category of the actuation needed.
 * Sample: Sample that caused an out of range status.
 * Setting: Setting that are violated by the sample current value.
 * Plan that is triggered when a Sample does not respect the current settings, only if the 
 * actuator BB contains the correct Category.
 */
+actuate(Category, Sample, Setting) : category(Category) <- actuate(Sample, Setting).

{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }
