import { getOrpIndex } from '../lib/rsvp'

type Props = {
  token: string
  chunkMode: boolean
}

export function WordDisplay({ token, chunkMode }: Props) {
  if (!token) {
    return (
      <div className="word-stage" aria-live="polite">
        <div className="word-guides" aria-hidden="true">
          <span className="guide-v" />
          <span className="guide-h" />
        </div>
        <div className="word-empty">Başlamak için oynat</div>
      </div>
    )
  }

  if (chunkMode || token.includes(' ')) {
    return (
      <div className="word-stage" aria-live="polite">
        <div className="word-guides" aria-hidden="true">
          <span className="guide-v" />
          <span className="guide-h" />
        </div>
        <div key={token} className="word-chunk">
          {token}
        </div>
      </div>
    )
  }

  const orp = getOrpIndex(token)
  const before = token.slice(0, orp)
  const focus = token[orp] ?? ''
  const after = token.slice(orp + 1)

  return (
    <div className="word-stage" aria-live="polite">
      <div className="word-guides" aria-hidden="true">
        <span className="guide-v" />
        <span className="guide-h" />
      </div>
      <div key={token} className="word-rsvp">
        <span className="word-before">{before}</span>
        <span className="word-orp">{focus}</span>
        <span className="word-after">{after}</span>
      </div>
    </div>
  )
}
