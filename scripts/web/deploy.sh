#!/usr/bin/env bash

OG_BRANCH=$(git branch --show-current)

echo "==========================================="
echo "deploying to production environment"
echo "==========================================="
echo ""

echo "step 1: updating main branch..."
git checkout main
git pull
echo ""

echo "step 2: rebasing prod with main..."
git checkout prod
git pull
git rebase main
git push --force-with-lease
echo ""

echo "==========================================="
echo "production environment deployed successfully!"
echo "==========================================="

git checkout "$OG_BRANCH"
