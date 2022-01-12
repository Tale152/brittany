// Agent communicationAgent in project greenhouse_core

/* Initial beliefs and rules */

/* Initial goals */

/* Plans */

/*
 * Devices: Devices that are involved to retrieve samples.
 * Samples: Samples retrieved by the devices.
 * Plan that is triggered when a new list of Devices has to be sampled. Once the
 * Samples are retrieved, they are updated in the SamplingArtifact.
 */
+communicate(Devices) <- getSamplesOperation(Devices, Samples); updateOperation(Samples).

{ include("$jacamoJar/templates/common-cartago.asl") }
{ include("$jacamoJar/templates/common-moise.asl") }
