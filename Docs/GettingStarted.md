# Getting Started

Mineverse Open Core v0.1.0 is a standalone Unreal Engine 5.6 runtime plugin for public integration contracts, schemas, and validation helpers.

The plugin has been validated with Unreal Engine 5.6 on Win64 as a consumer-installed plugin. It does not require Mineverse production gameplay modules, private configuration, content assets, Fab or Marketplace packages, private services, Oracle infrastructure, or UNIT economy implementations.

## Installation

1. Download `MineverseOpenCore-v0.1.0-UE5.6-Win64.zip` from the GitHub release.
2. Extract the archive.
3. Copy the extracted `MineverseOpenCore` plugin folder into your Unreal project under `Plugins/MineverseOpenCore`.
4. Enable the plugin in your project descriptor or in the Unreal Editor plugin browser.
5. Add the module dependency from your C++ module when you include the public headers.

```csharp
PublicDependencyModuleNames.AddRange(
    new[]
    {
        "MineverseOpenCore"
    });
```

## Public Headers

The v0.1.0 surface includes:

- `BitRobotSensorTypes.h`
- `BitRobotSensorDriverInterface.h`
- `DroneInterface.h`
- `UNITInterface.h`
- `BiomeResourceRow.h`
- `ResourceDefinitionRow.h`
- `WeaponDataRow.h`
- `MineverseOpenValidationTypes.h`

`MineverseOpenCore.h` is the lightweight public module include.

## Consumer Validation

The `Examples/ConsumerCompileTest` fixture is a minimal C++ module that can be copied into an unrelated Unreal Engine 5.6 project. It includes each public header, implements the sensor, drone, and UNIT interfaces, constructs each published schema, and exposes an editor automation smoke test under `Mineverse.OpenCore.Consumer.Contracts`.

## Boundary

Apache-2.0 applies only to the files intentionally published in this repository. It does not grant branding or trademark rights beyond identifying the origin of the project. Production gameplay, content assets, commercial implementations, security systems, private service integrations, operational configuration, and restricted third-party content remain outside this repository.
