# Philosophers Project Evaluation Guide

## Introduction
- Be polite, courteous, respectful, and constructive
- Discuss and identify potential project dysfunctions
- Keep an open mind regarding different interpretations of the project

## General Guidelines
1. Only grade work in the Git repository
2. Verify repository ownership and proper cloning
3. Check for malicious aliases
4. Review testing scripts together
5. Read the subject before evaluation
6. Zero tolerance for:
   - Segfaults
   - Unexpected terminations
   - Memory leaks
   - Norm errors
7. Use appropriate flags for violations
8. Don't edit files except configuration files
9. Use available tools (leaks, valgrind, e_fence)

## Mandatory Part Testing

### Error Handling
- Must follow C Norm
- No crashes, UB, memory leaks
- Consider hardware limitations

### Global Variables
- No global variables allowed for managing shared resources
- Immediate failure if found

### Code Requirements
1. Thread Management:
   - One thread per philosopher
   - One fork per philosopher
   - Mutex per fork for value management
2. Output Control:
   - No mixed outputs
   - Death verification with mutex protection

### Testing Scenarios
1. Basic Rules:
   - Max 200 philosophers
   - Minimum 60ms for time parameters
2. Test Cases:
   ```
   1 800 200 200    -> Should die
   5 800 200 200    -> No deaths
   5 800 200 200 7  -> No deaths, stop after 7 meals
   4 410 200 200    -> No deaths
   4 310 200 100    -> One death
   2 [custom times] -> Death delay < 10ms
   ```

## Bonus Part Testing

### Code Requirements
1. Process Management:
   - One process per philosopher
   - Main process not a philosopher
   - No orphan processes
2. Semaphore Usage:
   - Single semaphore for forks
   - Protected output access
   - Death verification with semaphore

### Testing Scenarios
Same test cases as mandatory part:
```
5 800 200 200
5 800 200 200 7
4 410 200 200
4 310 200 100
2 [custom times]
```

## Rating Options
- OK
- Outstanding
- Empty Work
- Incomplete Work
- Invalid Compilation
- Norme
- Cheat
- Crash
- Concerning Situations
- Leaks
- Forbidden Functions