# Open Core Scope

`Mineverse-Hub` is the clean public home for approved Mineverse open-core
framework material. Apache-2.0 applies only to material intentionally published
in this repository within the approved scope below.

## Published v0.1 Surface

`MineverseOpenCore` is a standalone Unreal Engine 5.6 runtime plugin. It
contains only public interfaces, schemas, extension contracts, and generic
validation structures. It does not depend on production Mineverse modules,
content assets, private configuration, Marketplace plugins, or private
services.

Approved public categories:

- framework contracts and extension points
- schema definitions for safe external integration
- validation structures and conformance documentation
- sanitized examples that do not copy production logic
- developer guidance for approved public APIs
- architecture notes that describe boundaries without exposing internal systems
- approved generic validation components

Excluded categories:

- complete gameplay implementations
- production `Private/` C++ implementations
- commercial tests and validation suites
- Oracle infrastructure, governance engines, or operational services
- UNIT economy implementations, ledgers, or production reward logic
- operational security, access gates, and private deployment tooling
- Fab, Unreal Marketplace, mannequin, or private content references
- Unreal project configuration, generated folders, patches, credentials, tokens,
  endpoints, and machine-local settings

Candidate open-core material must be reviewed file by file before publication.
Approved material should be authored or extracted into a clean public history,
with no inherited private commits and no dependency on restricted assets.

Apache-2.0 has been approved for the separately extracted Mineverse open-core
interfaces, schemas, extension contracts, and approved generic validation
components published through this repository. That approval does not extend to
the excluded categories above.
