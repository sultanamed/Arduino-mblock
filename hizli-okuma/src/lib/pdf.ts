import * as pdfjs from 'pdfjs-dist'
import pdfWorker from 'pdfjs-dist/build/pdf.worker.min.mjs?url'

pdfjs.GlobalWorkerOptions.workerSrc = pdfWorker

export type PdfLoadResult = {
  text: string
  pageCount: number
  fileName: string
}

export async function extractTextFromPdf(file: File): Promise<PdfLoadResult> {
  const buffer = await file.arrayBuffer()
  const loadingTask = pdfjs.getDocument({ data: buffer })
  const pdf = await loadingTask.promise

  const pages: string[] = []

  for (let pageNum = 1; pageNum <= pdf.numPages; pageNum += 1) {
    const page = await pdf.getPage(pageNum)
    const content = await page.getTextContent()
    const strings = content.items
      .map((item) => ('str' in item ? item.str : ''))
      .filter(Boolean)

    pages.push(strings.join(' '))
  }

  const text = pages
    .join('\n\n')
    .replace(/\u00ad/g, '')
    .replace(/[ \t]+\n/g, '\n')
    .replace(/\n{3,}/g, '\n\n')
    .replace(/[ \t]{2,}/g, ' ')
    .trim()

  if (!text) {
    throw new Error('Bu PDF’den okunabilir metin çıkarılamadı. Taranmış (görüntü) PDF olabilir.')
  }

  return {
    text,
    pageCount: pdf.numPages,
    fileName: file.name,
  }
}
