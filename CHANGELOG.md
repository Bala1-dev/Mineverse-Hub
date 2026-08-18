# Changelog

All notable public changes to Mineverse Open Core are documented here.

This repository follows an open-core stabilization track for the v0.1 public
API. The `v0.1.0` release remains a beta prerelease while independent external
validation is collected.

## Unreleased

### Stabilization

- Freeze the v0.1 public API after `v0.1.0`.
- Add public API stability guidance for the v0.1.x line.
- Add an external validation checklist for unrelated Unreal Engine 5.6 C++
  consumer projects.
- Add public issue forms for sanitized validation and bug reports.

No public interfaces, reflected types, schemas, module dependencies, release
artifacts, or `v0.1.0` tag contents are changed by these stabilization notes.

## v0.1.0 - 2026-08-18

### Added

- Published `MineverseOpenCore`, a standalone Unreal Engine 5.6 runtime plugin.
- Added public contracts for sensor, drone, and UNIT-compatible extension
  adapters.
- Added public schema rows for biome resources, resource definitions, and
  generic weapon metadata.
- Added public generic validation structures.
- Added a sanitized consumer compile-test fixture.
- Published a UE 5.6 Win64 prerelease archive and SHA-256 checksum.

### Boundary

- Production gameplay, Oracle infrastructure, UNIT economy implementations,
  operational security systems, premium Fab modules, content assets, private
  configuration, and commercial Mineverse technology remain excluded.
