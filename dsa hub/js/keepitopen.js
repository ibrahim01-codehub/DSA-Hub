const differenceReveal = document.querySelector(".difference-reveal");
const differenceTrigger = document.querySelector(".difference-trigger");

if (differenceReveal && differenceTrigger) {
    differenceTrigger.addEventListener("click", () => {
        const isOpen = differenceReveal.classList.toggle("is-open");
        differenceTrigger.setAttribute("aria-expanded", String(isOpen));
    });
}
