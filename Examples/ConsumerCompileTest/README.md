# Consumer Compile Test

This fixture is a sanitized Unreal Engine 5.6 C++ module for validating `MineverseOpenCore` as an external consumer.

It is intentionally not a full Unreal project. Copy the `Source/MineverseOpenCoreConsumerTest` module into a temporary C++ host project, install the `MineverseOpenCore` plugin under that project's `Plugins` folder, and add `MineverseOpenCoreConsumerTest` to the host project's target `ExtraModuleNames`.

The fixture:

- Includes every public plugin header.
- Implements the sensor, drone, and UNIT interfaces.
- Constructs the biome, resource, weapon, sensor, and validation schemas.
- Adds per-header self-containment translation units.
- Defines the editor automation test `Mineverse.OpenCore.Consumer.Contracts`.

It contains no production gameplay, private configuration, assets, endpoints, credentials, Fab or Marketplace dependencies, Oracle infrastructure, UNIT economy implementation, or private service integration.
