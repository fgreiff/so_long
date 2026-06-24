#!/bin/bash

echo "Testing VALID maps (should work):"
for map in map/map_valid_*.ber; do
    [ -f "$map" ] || continue
    echo -n "Testing $map: "
    timeout 2 ./so_long "$map" 2>/dev/null && echo "✓" || echo "✗"
done

echo ""
echo "Testing INVALID maps (should fail):"
for map in map/map_invalid_*.ber map/map_edge_*.ber; do
    [ -f "$map" ] || continue
    echo -n "Testing $map: "
    timeout 2 ./so_long "$map" 2>/dev/null && echo "✗ (Should have failed!)" || echo "✓"
done
