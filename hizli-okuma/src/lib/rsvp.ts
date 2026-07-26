/** ORP (Optimal Recognition Point) index for a word — classic Spritz-style pivot. */
export function getOrpIndex(word: string): number {
  const len = word.length
  if (len <= 1) return 0
  if (len <= 5) return 1
  if (len <= 9) return 2
  if (len <= 13) return 3
  return 4
}

export function tokenize(text: string): string[] {
  return text
    .replace(/\r\n/g, '\n')
    .split(/\s+/)
    .map((w) => w.trim())
    .filter((w) => w.length > 0)
}

export function chunkWords(words: string[], chunkSize: number): string[] {
  if (chunkSize <= 1) return words
  const chunks: string[] = []
  for (let i = 0; i < words.length; i += chunkSize) {
    chunks.push(words.slice(i, i + chunkSize).join(' '))
  }
  return chunks
}

/** Extra dwell time for punctuation / longer tokens (ms multiplier). */
export function dwellMultiplier(token: string): number {
  if (/[.!?…]["'”’)]*$/.test(token)) return 2.2
  if (/[,;:]["'”’)]*$/.test(token)) return 1.5
  if (token.length > 12) return 1.35
  if (token.length > 8) return 1.15
  return 1
}

export function wpmToIntervalMs(wpm: number): number {
  return Math.max(40, Math.round(60000 / Math.max(60, wpm)))
}

export function estimateMinutes(wordCount: number, wpm: number): number {
  return wordCount / Math.max(60, wpm)
}

export function formatDuration(minutes: number): string {
  if (!Number.isFinite(minutes) || minutes <= 0) return '—'
  if (minutes < 1) return `${Math.max(1, Math.round(minutes * 60))} sn`
  if (minutes < 60) return `${Math.round(minutes)} dk`
  const h = Math.floor(minutes / 60)
  const m = Math.round(minutes % 60)
  return `${h} sa ${m} dk`
}
