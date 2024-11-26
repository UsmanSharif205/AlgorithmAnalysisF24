/** @type {import('tailwindcss').Config} */
module.exports = {
  content: [
    "./src/pages/**/*.{js,ts,jsx,tsx,mdx}",
    "./src/components/**/*.{js,ts,jsx,tsx,mdx}",
    "./src/app/**/*.{js,ts,jsx,tsx,mdx}",
  ],
  theme: {
    extend: {
      colors: {
        background: "var(--background)",
        foreground: "var(--foreground)",
      },
      keyframes: {
        "rise-up": {
          "0%": { transform: "translateY(50px)", opacity: "0" },
          "100%": { transform: "translateY(0)", opacity: "1" },
        },
        "fire-glow": {
          "0%, 100%": {
            boxShadow:
              "0 0 10px 2px rgba(255, 85, 0, 0.8), 0 0 20px 5px rgba(255, 120, 0, 0.5)",
          },
          "50%": {
            boxShadow:
              "0 0 15px 5px rgba(255, 120, 0, 1), 0 0 25px 10px rgba(255, 165, 0, 0.7)",
          },
        },
      },
      animation: {
        "rise-up": "rise-up 1s ease-out forwards",
        "fire-glow": "fire-glow 1.5s ease-in-out infinite",
      },
    },
  },
  plugins: [],
};
