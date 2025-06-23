#!/bin/bash

NUM_TESTS=100
NUM_COUNT=500
MAX_OP=5500
OK=0
KO=0
TOTAL_OP=0

for i in $(seq 1 $NUM_TESTS); do
    ARG=$(shuf -i 0-999 -n $NUM_COUNT | xargs)
    OUT=$(./push_swap $ARG)
    RES=$(echo "$OUT" | ./tester/checker_linux $ARG)
    OP_COUNT=$(echo "$OUT" | wc -l)

    if [ "$RES" = "OK" ]; then
        ((OK++))
        TOTAL_OP=$((TOTAL_OP + OP_COUNT))
        if [ "$OP_COUNT" -gt "$MAX_OP" ]; then
            echo "⚠️  Test $i OK, but with $OP_COUNT operations (above $MAX_OP)"
        fi
    else
        ((KO++))
        echo "❌ Test $i => KO"
        echo "ARG: $ARG"
        echo "Operations:"
        echo "$OUT"
        echo "----------------------"
    fi
done

echo ""
echo "✅ Total OK: $OK"
echo "❌ Total KO: $KO"

if [ "$OK" -gt 0 ]; then
    AVG=$((TOTAL_OP / OK))
    echo "📊 Average of operations: $AVG"
fi
