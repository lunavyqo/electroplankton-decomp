# Claims

Coordinate so two people do not work the same address range.

Add a row when you start; remove or mark done when the range is matched or you
drop the claim.

| Module | Range (inclusive) | Claimant | Date (UTC) | Status | Notes |
|--------|-------------------|----------|------------|--------|-------|
| —      | —                 | —        | —          | —      | empty |

## How to claim

1. Pull latest `main`.
2. Append a row with your handle, the module (`arm9`, `arm7`, overlay id, …),
   and the address range you will work.
3. Prefer a small commit that only updates this file.
4. Work only inside your claimed range until you release it.
