import "./globals.css";

export const metadata = {
  title: "ChessGame",
  description: "A chess game made with ❤️ by @MuhammadArhum",
};

export default function RootLayout({ children }) {
  return (
    <html lang="en">
      <body>{children}</body>
    </html>
  );
}
