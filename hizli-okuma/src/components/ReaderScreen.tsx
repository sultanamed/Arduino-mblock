import { useEffect, useState } from 'react'
import { estimateMinutes, formatDuration } from '../lib/rsvp'
import { useRsvp } from '../hooks/useRsvp'
import { WordDisplay } from './WordDisplay'

type Props = {
  text: string
  fileName: string
  pageCount: number
  onReset: () => void
}

export function ReaderScreen({ text, fileName, pageCount, onReset }: Props) {
  const wordCount = text.trim().split(/\s+/).filter(Boolean).length
  const [wpm, setWpm] = useState(280)
  const [chunkSize, setChunkSize] = useState(1)

  const {
    tokens,
    index,
    current,
    playing,
    progress,
    toggle,
    skip,
    restart,
    seek,
  } = useRsvp({ text, wpm, chunkSize })

  useEffect(() => {
    const onKey = (e: KeyboardEvent) => {
      if (e.target instanceof HTMLInputElement || e.target instanceof HTMLTextAreaElement) return
      if (e.code === 'Space') {
        e.preventDefault()
        toggle()
      } else if (e.code === 'ArrowRight') {
        skip(chunkSize === 1 ? 5 : 2)
      } else if (e.code === 'ArrowLeft') {
        skip(chunkSize === 1 ? -5 : -2)
      } else if (e.code === 'ArrowUp') {
        e.preventDefault()
        setWpm((v) => Math.min(800, v + 20))
      } else if (e.code === 'ArrowDown') {
        e.preventDefault()
        setWpm((v) => Math.max(100, v - 20))
      }
    }
    window.addEventListener('keydown', onKey)
    return () => window.removeEventListener('keydown', onKey)
  }, [toggle, skip, chunkSize])

  const remaining = formatDuration(estimateMinutes(Math.max(0, tokens.length - index - 1), wpm))

  return (
    <section className="reader">
      <header className="reader-top">
        <button type="button" className="ghost-btn" onClick={onReset}>
          Yeni PDF
        </button>
        <div className="reader-meta">
          <p className="brand brand-sm">Akış</p>
          <p className="file-name" title={fileName}>
            {fileName}
          </p>
          <p className="file-stats">
            {pageCount} sayfa · {wordCount.toLocaleString('tr-TR')} kelime · ~{remaining} kaldı
          </p>
        </div>
      </header>

      <div className="reader-stage" onClick={toggle}>
        <WordDisplay token={current} chunkMode={chunkSize > 1} />
      </div>

      <div className="progress-wrap">
        <input
          className="progress"
          type="range"
          min={0}
          max={Math.max(0, tokens.length - 1)}
          value={index}
          onChange={(e) => seek(Number(e.target.value))}
          aria-label="İlerleme"
        />
        <div className="progress-labels">
          <span>
            {index + 1} / {tokens.length}
          </span>
          <span>{Math.round(progress * 100)}%</span>
        </div>
      </div>

      <div className="controls">
        <div className="control-row transport">
          <button type="button" className="icon-btn" onClick={() => skip(-10)} aria-label="10 geri">
            <SkipIcon dir="back" />
          </button>
          <button type="button" className="icon-btn" onClick={restart} aria-label="Baştan">
            <RestartIcon />
          </button>
          <button
            type="button"
            className="play-btn"
            onClick={toggle}
            aria-label={playing ? 'Duraklat' : 'Oynat'}
          >
            {playing ? 'Duraklat' : 'Oynat'}
          </button>
          <button type="button" className="icon-btn" onClick={() => skip(10)} aria-label="10 ileri">
            <SkipIcon dir="forward" />
          </button>
        </div>

        <div className="control-row sliders">
          <label className="slider-field">
            <span>
              Hız <strong>{wpm} WPM</strong>
            </span>
            <input
              type="range"
              min={100}
              max={800}
              step={10}
              value={wpm}
              onChange={(e) => setWpm(Number(e.target.value))}
            />
          </label>

          <label className="slider-field">
            <span>
              Grup <strong>{chunkSize} kelime</strong>
            </span>
            <input
              type="range"
              min={1}
              max={3}
              step={1}
              value={chunkSize}
              onChange={(e) => setChunkSize(Number(e.target.value))}
            />
          </label>
        </div>

        <p className="shortcuts">Boşluk: oynat/duraklat · ok tuşları: atla / hız</p>
      </div>
    </section>
  )
}

function SkipIcon({ dir }: { dir: 'back' | 'forward' }) {
  const flip = dir === 'back'
  return (
    <svg width="22" height="22" viewBox="0 0 24 24" fill="none" aria-hidden="true"
      style={flip ? { transform: 'scaleX(-1)' } : undefined}>
      <path d="M5 12h10M13 7l5 5-5 5" stroke="currentColor" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round" />
      <path d="M5 7v10" stroke="currentColor" strokeWidth="2" strokeLinecap="round" />
    </svg>
  )
}

function RestartIcon() {
  return (
    <svg width="22" height="22" viewBox="0 0 24 24" fill="none" aria-hidden="true">
      <path
        d="M4 12a8 8 0 1 1 2.3 5.5M4 12V7M4 12h5"
        stroke="currentColor"
        strokeWidth="2"
        strokeLinecap="round"
        strokeLinejoin="round"
      />
    </svg>
  )
}
