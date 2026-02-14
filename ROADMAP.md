# CNode Engine — v0.1.0

## Core

- Game Loop
- Fixed Timestep (SimulationUpdate 60 FPS)
- Time System
- Input System

## Math

- Vector2
- AABB
- Utility Math Functions

## World

- WorldScene
- Scene Management

## Node System

- GameNode
- Hierarquia (Parent / Children)
- Transform (estrutural)

## Component System

- Base Component
- Lifecycle (Update / SimulationUpdate / Destroy)
- Owner Reference (GameNode*)

## Componentes

- SpriteRenderer
- Rigidbody2D
- Collider2D
  - AABB Collider
  - Circle Collider
- ParticleEmitter
- BasicAnimator

## Rendering (SDL3)

- SDL_Renderer
- Render Pipeline Simples
- Draw Order
- Debug Rendering
- Camera System

## Partículas

- Estrutura de Partícula
- Sistema de Emissão
- Atualização
- Renderização CPU
