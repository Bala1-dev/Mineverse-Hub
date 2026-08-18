# External Validation

Mineverse Open Core v0.1.0 is ready for independent Unreal Engine 5.6 Win64
consumer validation. No independent human validation has been claimed yet.

Use a new unrelated Unreal Engine 5.6 C++ project. Do not use a Mineverse
production project, private repository, existing development checkout, or any
project containing private configuration or content.

## Checklist

- Download the `v0.1.0` release archive anonymously from GitHub.
- Download the `v0.1.0` SHA-256 checksum file anonymously from GitHub.
- Verify the ZIP SHA-256 checksum before extracting it.
- Install `MineverseOpenCore` into a new unrelated Unreal Engine 5.6 C++
  project under `Plugins/MineverseOpenCore`.
- Build `UnrealEditor` Win64 Development.
- Build `UnrealGame` Win64 Development.
- Build `UnrealGame` Win64 Shipping.
- Run the automation test `Mineverse.OpenCore.Consumer.Contracts`.
- Confirm no private Mineverse module, configuration, asset, service, endpoint,
  content directory, Fab or Marketplace dependency, Oracle infrastructure, UNIT
  economy implementation, or production gameplay dependency is required.
- Report the result through the external validation issue form without posting
  secrets, private paths, full machine identifiers, credentials, or sensitive
  logs.

## Report Contents

External reports should include only:

- Unreal Engine version and source
- operating system
- compiler and toolchain
- installation method
- build targets attempted
- automation-test result
- concise error summary with credentials and private paths removed

Do not paste raw tokens, private URLs, local secrets, customer data, device
identifiers, full logs that expose machine paths, or unpublished security
details into a public issue.

Security-sensitive findings must be reported through GitHub private
vulnerability reporting or another private maintainer channel.
