import { useCallback, useRef, useState, type DragEvent } from 'react'

type Props = {
  onFile: (file: File) => void
  onDemo: () => void
  loading: boolean
  error: string | null
}

export function UploadScreen({ onFile, onDemo, loading, error }: Props) {
  const inputRef = useRef<HTMLInputElement>(null)
  const [dragging, setDragging] = useState(false)

  const accept = useCallback(
    (file: File | undefined) => {
      if (!file) return
      if (file.type !== 'application/pdf' && !file.name.toLowerCase().endsWith('.pdf')) {
        return
      }
      onFile(file)
    },
    [onFile],
  )

  const onDrop = useCallback(
    (e: DragEvent) => {
      e.preventDefault()
      setDragging(false)
      accept(e.dataTransfer.files?.[0])
    },
    [accept],
  )

  return (
    <section className="hero">
      <div className="hero-atmosphere" aria-hidden="true" />
      <div className="hero-content">
        <p className="brand">Akış</p>
        <h1 className="hero-title">PDF’ini yükle, gözün kelimeleri yakalasın.</h1>
        <p className="hero-sub">
          RSVP tekniğiyle metin tek tek akar — tabletinde hızını sen ayarla.
        </p>

        <div
          className={`dropzone ${dragging ? 'is-dragging' : ''} ${loading ? 'is-loading' : ''}`}
          onDragEnter={(e) => {
            e.preventDefault()
            setDragging(true)
          }}
          onDragOver={(e) => e.preventDefault()}
          onDragLeave={() => setDragging(false)}
          onDrop={onDrop}
          onClick={() => !loading && inputRef.current?.click()}
          role="button"
          tabIndex={0}
          onKeyDown={(e) => {
            if (e.key === 'Enter' || e.key === ' ') {
              e.preventDefault()
              inputRef.current?.click()
            }
          }}
          aria-label="PDF yükle"
        >
          <input
            ref={inputRef}
            type="file"
            accept="application/pdf,.pdf"
            hidden
            onChange={(e) => accept(e.target.files?.[0])}
          />
          <div className="dropzone-icon" aria-hidden="true">
            <svg width="40" height="40" viewBox="0 0 40 40" fill="none">
              <path
                d="M20 8v16M20 8l-6 6M20 8l6 6M8 28v2a2 2 0 002 2h20a2 2 0 002-2v-2"
                stroke="currentColor"
                strokeWidth="2.2"
                strokeLinecap="round"
                strokeLinejoin="round"
              />
            </svg>
          </div>
          <strong>{loading ? 'PDF okunuyor…' : 'PDF seç veya sürükle'}</strong>
          <span>Metin içeren PDF’ler desteklenir · iPad / Mac</span>
        </div>

        {error ? <p className="error-banner">{error}</p> : null}

        <button type="button" className="demo-btn" onClick={onDemo} disabled={loading}>
          Önce örnek metinle dene
        </button>

        <ul className="hero-hints">
          <li>Kelime kelime (RSVP) veya 2–3’lü grup</li>
          <li>100–800 WPM hız kontrolü</li>
          <li>Dosya cihazında kalır, sunucuya gitmez</li>
        </ul>
      </div>
    </section>
  )
}
