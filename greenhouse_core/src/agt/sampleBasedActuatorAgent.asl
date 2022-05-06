// Agent sampleBasedActuatorAgent in project greenhouse_core

/* Plans */

/*
 * Components: the list of components found in the greenhouse.
 * Plan that is triggered when new components are found and the observable property
 * is updated.
 */
+setupComponents(Components) <- setupComponents(Components).

/*
 * Tds: the list of thing descriptor that contains all the properties and the 
 * actions of all the components in the greenhouse.
 * Plan that is triggered when new tds are found and the observable property
 * is updated.
 */
+setupTds(Tds) <- setupTds(Tds).

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
