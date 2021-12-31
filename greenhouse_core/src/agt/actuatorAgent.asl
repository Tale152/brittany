// Agent actuatorAgent in project greenhouse_core

/* Initial beliefs and rules */

/* Initial goals */

/* Plans */

/*
 * SA: Sample that caused an out of range status.
 * SE: Settings that are violated by the sample current value.
 * Plan that is triggered when a Sample does not respect the current settings.
 */
+actuate(Sample, Setting) <- actuate(Sample, Setting).

{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }
