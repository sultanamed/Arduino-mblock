import { useCallback, useState } from 'react'
import { UploadScreen } from './components/UploadScreen'
import { ReaderScreen } from './components/ReaderScreen'
import type { PdfLoadResult } from './lib/pdf'
import { DEMO_TEXT } from './lib/demo'
import './App.css'

export default function App() {
  const [doc, setDoc] = useState<PdfLoadResult | null>(null)
  const [loading, setLoading] = useState(false)
  const [error, setError] = useState<string | null>(null)

  const onFile = useCallback(async (file: File) => {
    setLoading(true)
    setError(null)
    try {
      const { extractTextFromPdf } = await import('./lib/pdf')
      const result = await extractTextFromPdf(file)
      setDoc(result)
    } catch (err) {
      const message =
        err instanceof Error ? err.message : 'PDF okunamadı. Lütfen başka bir dosya dene.'
      setError(message)
      setDoc(null)
    } finally {
      setLoading(false)
    }
  }, [])

  const onDemo = useCallback(() => {
    setError(null)
    setDoc({
      text: DEMO_TEXT,
      pageCount: 1,
      fileName: 'ornek-metin.txt',
    })
  }, [])

  const onReset = useCallback(() => {
    setDoc(null)
    setError(null)
  }, [])

  if (doc) {
    return (
      <main className="app">
        <ReaderScreen
          text={doc.text}
          fileName={doc.fileName}
          pageCount={doc.pageCount}
          onReset={onReset}
        />
      </main>
    )
  }

  return (
    <main className="app">
      <UploadScreen onFile={onFile} onDemo={onDemo} loading={loading} error={error} />
    </main>
  )
}
