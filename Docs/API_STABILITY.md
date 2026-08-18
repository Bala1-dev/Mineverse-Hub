# API Stability

Mineverse Open Core v0.1 is frozen as of the `v0.1.0` prerelease.

The frozen v0.1 public API includes the public headers, reflected types,
schemas, extension contracts, plugin descriptor module identity, and module
dependencies published in `MineverseOpenCore`.

## v0.1.x Policy

The v0.1.x line permits only:

- defect fixes
- documentation corrections
- packaging corrections
- security corrections
- confirmed Unreal Engine 5.6 compatibility fixes

v0.1.x changes must not add new public interfaces, rename reflected symbols,
remove fields, change schema meaning, add private service dependencies, add
content requirements, or expand module dependencies beyond the current public
set.

The current `MineverseOpenCore` module dependencies are:

- `Core`
- `CoreUObject`
- `Engine`

## Future v0.2.0 Review

New interfaces, breaking changes, schema revisions, renamed reflected types,
dependency expansion, or material changes to integration behavior require a
future v0.2.0 review. That review must preserve the open-core boundary and must
not import production implementation, restricted assets, private configuration,
or commercial Mineverse technology.

## Exclusions

The v0.1 API freeze does not expose or stabilize private Mineverse systems.
Production gameplay, Oracle infrastructure, UNIT economy implementations,
operational security, premium Fab modules, content assets, private services,
deployment configuration, and internal technology remain outside the public API
and outside the Apache-2.0 grant for this repository.
