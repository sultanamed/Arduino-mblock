import { useCallback, useEffect, useMemo, useRef, useState } from 'react'
import { chunkWords, dwellMultiplier, tokenize, wpmToIntervalMs } from '../lib/rsvp'

export type UseRsvpOptions = {
  text: string
  wpm: number
  chunkSize: number
}

export function useRsvp({ text, wpm, chunkSize }: UseRsvpOptions) {
  const tokens = useMemo(() => chunkWords(tokenize(text), chunkSize), [text, chunkSize])
  const [index, setIndex] = useState(0)
  const [playing, setPlaying] = useState(false)
  const timerRef = useRef<number | null>(null)
  const indexRef = useRef(0)
  const playingRef = useRef(false)
  const tokensRef = useRef(tokens)
  const wpmRef = useRef(wpm)

  indexRef.current = index
  playingRef.current = playing
  tokensRef.current = tokens
  wpmRef.current = wpm

  const clearTimer = useCallback(() => {
    if (timerRef.current !== null) {
      window.clearTimeout(timerRef.current)
      timerRef.current = null
    }
  }, [])

  const stop = useCallback(() => {
    clearTimer()
    setPlaying(false)
  }, [clearTimer])

  useEffect(() => {
    clearTimer()
    if (!playing) return

    const tick = () => {
      const list = tokensRef.current
      const current = list[indexRef.current]
      if (!current) {
        setPlaying(false)
        return
      }

      const delay = wpmToIntervalMs(wpmRef.current) * dwellMultiplier(current)
      timerRef.current = window.setTimeout(() => {
        setIndex((prev) => {
          if (prev >= list.length - 1) {
            setPlaying(false)
            return prev
          }
          return prev + 1
        })
      }, delay)
    }

    tick()
    return clearTimer
  }, [playing, index, wpm, clearTimer])

  useEffect(() => {
    clearTimer()
    setPlaying(false)
    setIndex(0)
  }, [text, chunkSize, clearTimer])

  const play = useCallback(() => {
    if (tokensRef.current.length === 0) return
    if (indexRef.current >= tokensRef.current.length - 1) {
      setIndex(0)
    }
    setPlaying(true)
  }, [])

  const pause = useCallback(() => {
    setPlaying(false)
  }, [])

  const toggle = useCallback(() => {
    if (playingRef.current) pause()
    else play()
  }, [pause, play])

  const seek = useCallback((next: number) => {
    const clamped = Math.max(0, Math.min(tokensRef.current.length - 1, next))
    setIndex(clamped)
  }, [])

  const skip = useCallback(
    (delta: number) => {
      seek(indexRef.current + delta)
    },
    [seek],
  )

  const restart = useCallback(() => {
    clearTimer()
    setIndex(0)
    setPlaying(false)
  }, [clearTimer])

  return {
    tokens,
    index,
    current: tokens[index] ?? '',
    playing,
    progress: tokens.length ? (index + 1) / tokens.length : 0,
    play,
    pause,
    toggle,
    stop,
    seek,
    skip,
    restart,
  }
}
