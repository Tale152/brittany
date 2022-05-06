// Agent samplingAgent in project greenhouse_core

/* Plans */

/*
 * Tds: the list of thing descriptor that contains all the properties and the 
 * actions of all the components in the greenhouse.
 * Plan that is triggered when new tds are found and the observable property
 * is updated.
 */
+setupTds(Tds) <- setupTds(Tds).

/*
 * Components: Components that are involved to retrieve samples, which are part of a specific
 * category.
 * Plan that is triggered when a list of Components has to be sampled.
 */
+communicate(Components) <- getSamples(Components).

{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }
